const express = require("express");
const controller = require("./controller/inventario.controller");
const app = express();
app.use(express.json());
app.post("/inventario", controller.cadastrar);
app.get("/inventario", controller.listar);
app.get("/inventario/:id", controller.buscarPorId);
app.put("/inventario/:id", controller.atualizar);
app.delete("/inventario/:id", controller.excluir);
app.listen(3000, () => {
    console.log("Servidor rodando em http://localhost:3000");
});