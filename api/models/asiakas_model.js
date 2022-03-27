const db = require('../database');

const asiakas = {
  get: function (callback) {
    return db.query('select * from asiakas', callback);
  },
  getById: function (id, callback) {
    return db.query('select * from asiakas where id=?', [id], callback);
  },
  add: function (asiakas, callback) {
    return db.query('insert into asiakas (tunnus, etunimi, sukunimi, osoite, puhelin) values(?,?,?,?,?)',
      [asiakas.tunnus, asiakas.etunimi, asiakas.sukunimi, asiakas.osoite, asiakas.puhelin], callback);
  },
  delete: function (id, callback) {
    return db.query('delete from asiakas where id=?', [id], callback);
  },
  update: function (id, asiakas, callback) {
    return db.query('update asiakas set tunnus=?, etunimi=?, sukunimi=?, osoite=?, puhelin=? where id=?',
      [asiakas.tunnus, asiakas.etunimi, asiakas.sukunimi, asiakas.osoite, asiakas.puhelin, id], callback);
  }

}

module.exports = asiakas;