const service = require("../service/inventario.service");
function cadastrar(req, res) {
    let {
        item,
        local,
        dataRegistro,
        valor,
        patrimonio
    } = req.body;
    let novoItem = service.cadastrar(
        item,
        local,
        dataRegistro,
        valor,
        patrimonio
    );
    res.status(201).json(novoItem);
}

function listar(req, res) {
    let inventario = service.listar();
    res.status(200).json(inventario);
}

function buscarPorId(req, res) {
    let id = req.params.id;
    let item = service.buscarPorId(id);
    if (!item) {
        return res.status(404).json({
            mensagem: "Item não encontrado"
        });
    }
    res.status(200).json(item);
}

function atualizar(req, res) {
    let id = req.params.id;
    let {
        item,
        local,
        dataRegistro,
        valor,
        patrimonio
    } = req.body;
    let itemAtualizado = service.atualizar(
        id,
        item,
        local,
        dataRegistro,
        valor,
        patrimonio
    );
    if (!itemAtualizado) {
        return res.status(404).json({
            mensagem: "Item não encontrado"
        });
    }
    res.status(200).json(itemAtualizado);
}

function excluir(req, res) {
    let id = req.params.id;
    let excluido = service.excluir(id);
    if (!excluido) {
        return res.status(404).json({
            mensagem: "Item não encontrado"
        });
    }
    res.status(200).json({
        mensagem: "Item excluído com sucesso"
    });
}
module.exports = {
    cadastrar,
    listar,
    buscarPorId,
    atualizar,
    excluir
};