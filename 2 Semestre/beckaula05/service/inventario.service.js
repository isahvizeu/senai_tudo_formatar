const fs = require("fs");
let inventario = require("../inventario.json");
function salvar() {
    fs.writeFileSync(
        "./inventario.json",
        JSON.stringify(inventario, null, 4)
    );
}

function cadastrar(item, local, dataRegistro, valor, patrimonio) {
    let id = 1;
    if (inventario.length > 0) {
        id = inventario[inventario.length - 1].id + 1;
    }
    let novoItem = {
        id,
        item,
        local,
        dataRegistro,
        valor,
        patrimonio
    };
    inventario.push(novoItem);
    salvar();
    return novoItem;
}

function listar() {
    return inventario;
}

function buscarPorId(id) {
    return inventario.find(
        item => item.id == id
    );
}

function atualizar(id, item, local, dataRegistro, valor, patrimonio) {
    let indice = inventario.findIndex(
        item => item.id == id
    );
    if (indice == -1) {
        return null;
    }
    inventario[indice] = {
        id: Number(id),
        item,
        local,
        dataRegistro,
        valor,
        patrimonio
    };
    salvar();
    return inventario[indice];
}

function excluir(id) {
    let indice = inventario.findIndex(
        item => item.id == id
    );
    if (indice == -1) {
        return false;
    }
    inventario.splice(indice, 1);
    salvar();
    return true;
}

module.exports = {
    cadastrar,
    listar,
    buscarPorId,
    atualizar,
    excluir
};