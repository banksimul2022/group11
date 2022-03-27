const db = require('../database');

const tili = {
  get: function (callback) {
    return db.query('select * from tili', callback);
  },
  getById: function (id, callback) {
    return db.query('select * from tili where id=?', [id], callback);
  },
  add: function (tili, callback) {
    return db.query('insert into tili (tilinumero, saldo) values(?,?)',
      [tili.tilinumero, tili.saldo], callback);
  },
  delete: function (id, callback) {
    return db.query('delete from tili where id=?', [id], callback);
  },
  update: function (id, tili, callback) {
    return db.query('update tili set tilinumero=?, saldo=? where id=?',
      [tili.tilinumero, tili.saldo, id], callback);
  }

}

module.exports = tili;