const db = require('../database');
const bcrypt = require('bcryptjs');

const saltRounds = 11;

const kortti = {
  get: function (callback) {
    return db.query('select * from kortti', callback);
  },
  getById: function (id, callback) {
    return db.query('select * from kortti where id=?', [id], callback);
  },
  add: function (kortti, callback) {
    bcrypt.hash(kortti.pinKoodi, saltRounds, function(err, hash) {
      return db.query('insert into kortti (idAsiakasTili, korttiNumero, pinKoodi, lukittu) values(?,?,?,?)',
        [kortti.idAsiakasTili, kortti.korttiNumero, hash, kortti.lukittu], callback);
    });
  },
  delete: function (id, callback) {
    return db.query('delete from kortti where id=?', [id], callback); //Varsinainen kortin poisto tapahtuu cascadella tililtä
  },
  update: function (id, kortti, callback) {
    bcrypt.hash(kortti.pinKoodi, saltRounds, function(err, hash) {
      return db.query('update kortti set idAsiakasTili=?, korttiNumero=?, pinKoodi=?, lukittu=? where id=?',
      [kortti.idAsiakasTili, kortti.korttiNumero, hash, kortti.lukittu, id], callback);
    });
  }

}

module.exports = kortti;