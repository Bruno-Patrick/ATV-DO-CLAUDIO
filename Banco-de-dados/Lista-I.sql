CREATE TABLE pacote (pct_codigo CHAR(12) NOT NULL PRIMARY KEY, pct_nome_origem VARCHAR(60), pct_nome_destino VARCHAR(60), pct_preco DECIMAL(8,2), ope_codigo CHAR(8), pct_data_inicio DATE, pct_data_fim DATE, pct_tipo INT CHECK(pct_tipo = 1 or pct_tipo = 2), FOREIGN KEY(ope_codigo) REFERENCES operadora(ope_codigo));

CREATE TABLE operadora (ope_codigo CHAR(8) NOT NULL PRIMARY KEY, ope_nome VARCHAR(30), ope_endereco VARCHAR(30), ope_codigo_cidade CHAR(12), ope_telefone VARCHAR(20), ope_contato VARCHAR(30));

CREATE TABLE cliente (cli_cpf VARCHAR(11) NOT NULL PRIMARY KEY, cli_nome VARCHAR(60), cli_endereco VARCHAR(30), cid_codigo CHAR(8), FOREIGN KEY(cid_codigo) REFERENCES cidade(cid_codigo));

CREATE TABLE pacote_trajeto (pct_codigo CHAR(12), cid_codigo CHAR(8), FOREIGN KEY(pct_codigo) REFERENCES pacote(pct_codigo), FOREIGN KEY(cid_codigo) REFERENCES cidade(cid_codigo));

CREATE TABLE cidade (cid_codigo CHAR(8) NOT NULL PRIMARY KEY, cid_nome VARCHAR(30), cid_estado VARCHAR(30));

CREATE TABLE vendas (ven_codigo CHAR(8) NOT NULL PRIMARY KEY, cli_cpf CHAR(11), pct_codigo CHAR(12), ven_data_venda DATE, FOREIGN KEY(cli_cpf) REFERENCES cliente(cli_cpf), FOREIGN KEY(pct_codigo) REFERENCES pacote(pct_codigo));

CREATE TABLE pagamento (ven_codigo CHAR(8), pag_num_parcela INT(2), pag_valor DECIMAL(8,2), pag_data_vencto DATE, pag_data_pagto DATE, pag_tipo CHAR(1) CHECK(pag_tipo = 'D' OR pag_tipo = 'C' OR pag_tipo = 'A'), FOREIGN KEY(ven_codigo) REFERENCES vendas(ven_codigo));

CREATE TABLE pag_check (ven_codigo CHAR(8), pag_num_parcela INT(2), pag_valor DECIMAL(8,2), cheque_numero VARCHAR(8), cheque_banco VARCHAR(12), cheque_data_deposito DATE, FOREIGN KEY(ven_codigo) REFERENCES vendas(ven_codigo));

INSERT INTO pacote (pct_codigo, pct_nome_origem, pct_nome_destino, pct_preco, ope_codigo, pct_data_inicio, pct_data_fim, pct_tipo) VALUES
('112233445566', 'São Paulo', 'Maceió', 30.0, '87654321', '2003-01-28', '2003-06-05', 1),
('1233445566', 'São Paulo', 'Rio de Janeiro', 30.0, '87654321', '2003-02-28', '2003-06-05', 1),
('12334566', 'Rio de Janeiro', 'Rio de Janeiro', 30.0, '87654323', '2003-03-28', '2003-06-05', 1);

INSERT INTO operadora VALUES
('87654321', 'Rbtrans', 'Castelo Branco', '123456789123', '68999811680', '6899775447'),
('87654323', 'RbtrAansS', 'Castelo Branco', '123456789123', '68999811680', '6899775447');

INSERT INTO cliente (cli_cpf, cli_nome, cli_endereco, cid_codigo) VALUES
('02463101202', 'Elias Cacau', 'Rua Ametista', '12345678'),
('02463101201', 'Souza Cacau', 'Rua Ametista', '1234578'),
('02463101204', 'Sou Astro', 'Rua Anastacia', '5678952'),
('02463101203', 'Kleber Camargo', 'Rua Ametista', '12345678');

INSERT INTO cidade (cid_codigo, cid_nome, cid_estado) VALUES
('12345678', 'Tarauacá','Acre'),
('56789552', 'Feijó','Acre');

INSERT INTO vendas (ven_codigo, cli_cpf, pct_codigo, ven_data_venda) VALUES
('12345', '02463101202','112233445566','2003-02-28'),
('1235', '02463101204','112233445566','2003-01-28');

-- SELECT * FROM emprestimo e
-- INNER JOIN tomador t
-- ON e.numero_emprestimo = t.numero_emprestimo;

-- SELECT cliente.cli_nome 
-- FROM cliente, cidade
-- WHERE cid_nome NOT LIKE "Marília";

-- SELECT DISTINCT cli_nome
-- FROM (cliente INNER JOIN cidade)
-- WHERE cid_nome NOT LIKE "Marília";

-- SELECT pct_codigo, ope_nome, pct_preco FROM pacote, operadora
-- WHERE pct_nome_origem LIKE "São Paulo" AND pct_nome_destino LIKE "Maceió";

-- SELECT pct_codigo, ope_nome, pct_preco
-- FROM pacote p INNER JOIN operadora o
-- ON p.pct_nome_origem LIKE "São Paulo"
-- AND p.pct_nome_destino LIKE "Maceió";

-- SELECT DISTINCT ope_nome FROM operadora LEFT JOIN pacote
-- ON pct_nome_destino LIKE "Rio de Janeiro"
-- OR pct_nome_origem LIKE "Rio de Janeiro";

-- SELECT cli_nome FROM cliente c
-- WHERE c.cid_codigo = (SELECT cid_codigo FROM cliente WHERE cli_nome LIKE "Kleber Camargo");

-- SELECT pct_nome_origem FROM pacote p 
-- WHERE p.pct_data_inicio LIKE "%-01-%";

-- SELECT DISTINCT cli_nome FROM cliente c INNER JOIN vendas v
-- ON c.cli_cpf = v.cli_cpf
-- AND v.ven_data_venda LIKE "%-01-%";

SELECT DISTINCT cli_nome FROM (cliente c CROSS JOIN cidade ci) CROSS JOIN (vendas v)
ON ((c.cid_codigo = ci.cid_codigo AND ci.cid_nome LIKE "Rio de Janeiro")
OR v.ven_data_venda LIKE "%-01-%");