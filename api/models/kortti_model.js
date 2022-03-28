const db = require('../database');

const kortti = {
  get: function (callback) {
    return db.query('select * from kortti', callback);
  },
  getById: function (id, callback) {
    return db.query('select * from kortti where id=?', [id], callback);
  },
  add: function (asiakas, callback) {
    return db.query('insert into kortti (korttiNumero, pinKoodi, lukittu) values(?,?,?)',
      [kortti.korttiNumero, kortti.pinKoodi, kortti.lukittu], callback);
  },
  delete: function (id, callback) {
    return db.query('delete from kortti where id=?', [id], callback);
  },
  update: function (id, asiakas, callback) {
    return db.query('update kortti set korttiNumero=?, pinKoodi=?, lukittu=? where id=?',
      [kortti.korttiNumero, kortti.pinKoodi, kortti.lukittu, id], callback);
  }

}

module.exports = kortti;