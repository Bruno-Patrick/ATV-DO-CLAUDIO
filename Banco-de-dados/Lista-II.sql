CREATE TABLE empregado(RG BIGINT(8) NOT NULL, sexo VARCHAR(1) NOT NULL, dt_nasc DATE NOT NULL,
pnome VARCHAR(40) NOT NULL, unome VARCHAR(40) NOT NULL, rua VARCHAR(40) NOT NULL, cidade VARCHAR(20) NOT NULL,
estado VARCHAR(20) NOT NULL, salario FLOAT(10,2), dnum BIGINT(8), supRG BIGINT(8) NOT NULL,
PRIMARY KEY(RG), FOREIGN KEY(dnum) REFERENCES departamento(dnum), FOREIGN KEY(supRG) REFERENCES empregado(RG) );

CREATE TABLE departamento(dnum BIGINT(8) NOT NULL, dnome VARCHAR(20) NOT NULL, gerRG BIGINT(8) NOT NULL,
dt_inicio DATE NOT NULL, FOREIGN KEY(gerRG) REFERENCES empregado(RG), PRIMARY KEY(dnum) );

CREATE TABLE projeto(pnum BIGINT(8) NOT NULL, pnome  VARCHAR(20) NOT NULL, localizacao VARCHAR(20) NOT NULL,
dnum BIGINT(8) NOT NULL, FOREIGN KEY(dnum) REFERENCES departamento(dnum), PRIMARY KEY(pnum) );

CREATE TABLE dependente(dep_nome VARCHAR(60) NOT NULL, dep_sexo VARCHAR(1) NOT NULL, dep_dt_nasc DATE NOT NULL,
empRG BIGINT(8) NOT NULL, FOREIGN KEY(empRG) REFERENCES empregado(RG), PRIMARY KEY(dep_nome) );

CREATE TABLE trabalha_em(RG BIGINT(8) NOT NULL, pnum BIGINT(8) NOT NULL, horas FLOAT(4,2) NOT NULL,
FOREIGN KEY(RG) REFERENCES empregado(RG), FOREIGN KEY(pnum) REFERENCES projeto(pnum) );

CREATE TABLE localizacao(localizacao VARCHAR(20) NOT NULL, dnum BIGINT(8) NOT NULL,
PRIMARY KEY(localizacao), FOREIGN KEY(dnum) REFERENCES departamento(dnum) );

INSERT INTO empregado VALUES
(17446116, 'M', '2002-05-17', 'Bruno', 'Supervisor', 'Rua do Alfineiros', 'Rio Branco', 'Acre', 4300.57, 5, 17446116),
(17446113, 'M', '2002-05-17', 'BRUNA', 'Supervisor', 'Rua do Alfineiros', 'Rio Branco', 'Acre', 4300.57, 5, 17446113),
(17446117, 'M', '2002-05-17', 'Bruna', 'Patricka', 'Rua do Alfineiros', 'Rio Branco', 'Acre', 4500.57, 5, 17446116),
(17446118, 'M', '2002-05-17', 'Brune', 'Patricke', 'Rua do Alfineiros', 'Rio Branco', 'Acre', 800.57, 4, 17446113);

INSERT INTO departamento VALUES
(5, 'Pesquisa',17446116, '2020-05-17'),
(4, 'RH',17446116, '2020-05-17');

INSERT INTO projeto VALUES
(1, 'Genoma Humano', 'Rua do Alfineiros', 4),
(2, 'Pesquisa', 'Londrina', 5);

INSERT INTO dependente VALUES
('Bruno Patrick', 'M', '2002-05-17', 17446116);

INSERT INTO localizacao VALUES
('Uuma loc ai',5),
('Uuma loc',4);

-- SELECT * FROM empregado e
-- WHERE e.dnum = 5;

-- SELECT * FROM empregado
-- WHERE dnum = 5 AND salario > 3000;

-- SELECT * FROM empregado e
-- WHERE (e.dnum = 5 AND e.salario > 300)
-- OR (e.dnum = 4 AND e.salario > 2000);

-- SELECT pnome, salario FROM empregado
-- WHERE dnum = 5;

-- SELECT RG FROM empregado
-- WHERE dnum = 5 OR RG = supRG;

-- SELECT pnome FROM empregado e INNER JOIN dependente d
-- ON CONCAT(e.pnome,' ',e.unome) = d.dep_nome;

-- SELECT CONCAT(e.pnome,' ',e.unome,' ',dep_nome) 'Combinações' FROM empregado e INNER JOIN dependente d
-- ON e.RG = d.empRG;

-- SELECT CONCAT(e.pnome,' ',e.unome) 'nome empregado', d.dep_nome FROM empregado e INNER JOIN dependente d
-- ON e.RG = d.empRG;

-- SELECT CONCAT(pnome,' ',unome) 'Nome do Gerente' FROM empregado e INNER JOIN departamento d
-- ON e.RG = d.gerRG;

-- SELECT localizacao FROM departamento d NATURAL JOIN localizacao l;
 
-- SELECT CONCAT(e.pnome,' ',e.unome) 'Nome do Empregado', p.pnum FROM empregado e RIGHT JOIN projeto p
-- ON e.dnum = p.dnum;

-- SELECT CONCAT(e.pnome,' ',e.unome) 'nome empregado',p.dnum
-- FROM empregado e INNER JOIN projeto p
-- ON e.dnum = 5 AND p.dnum = 5;

-- SELECT COUNT(pnome) 'quantidade de empregados' FROM empregado;

-- SELECT AVG(salario) 'Media salarial', e.dnum FROM empregado e
-- GROUP BY e.dnum;

-- SELECT CONCAT(e.pnome,' ',e.unome) 'nome do funcionario', CONCAT(e.rua,' - ',e.cidade,', ',e.estado) 'Endereco'
-- FROM empregado e INNER JOIN projeto p
-- ON e.dnum = p.dnum AND p.pnome LIKE 'Pesquisa';

-- SELECT p.pnum, p.dnum, CONCAT(e.pnome,' ',e.unome) 'Gerente', e.sexo
-- FROM empregado e INNER JOIN projeto p
-- ON p.localizacao LIKE 'Londrina' AND p.dnum = e.dnum
-- AND e.supRG = e.RG;
