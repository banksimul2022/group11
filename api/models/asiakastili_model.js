const db = require("../database");

const asiakastili = {
  get: function (callback) {
    return db.query("SELECT * FROM asiakasTili", callback);
  },
  getById: function (id, callback) {
    return db.query("SELECT * FROM asiakasTili WHERE id=?", [id], callback);
  },
  getByIdAsiakas: function (id, callback) {
    return db.query(
      "SELECT * FROM asiakasTili WHERE idAsiakas=?",
      [id],
      callback
    );
  },
  getByIdTili: function (id, callback) {
    return db.query("SELECT * FROM asiakasTili WHERE idTili=?", [id], callback);
  },
  add: function (body, callback) {
    return db.query(
      "INSERT INTO asiakasTili (idAsiakas, idTili) VALUES (?,?)",
      [body.idAsiakas, body.idTili],
      callback
    );
  },
  delete: function (id, callback) {
    return db.query("DELETE FROM asiakasTili WHERE id=?", [id], callback);
  },
  update: function (id, body, callback) {
    return db.query(
      "UPDATE asiakasTili SET idAsiakas=?, idTili=? WHERE id=?",
      [body.idAsiakas, body.idTili, id],
      callback
    );
  },
};

module.exports = asiakastili;
