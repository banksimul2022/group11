const db = require('../database')

//Aikaleiman muoto on YYYY-MM-DDTHH:MM:SS.000Z

const tilitapahtuma = {
  get: function (callback) {
    return db.query('select * from tilitapahtuma', callback)                     //Haetaan kaikki tapahtumat listausta varten
  },
  getById: function (id, callback) {                                              //Haetaan yksittäinen tapahtuma id:n mukaan
    return db.query('select * from tilitapahtuma where id=?', [id], callback)
  },
  add: function (tilitapahtuma, callback) {                                       //Tässä operaatio jos asiakas nostaa, lisää tai siirtää rahaa
    return db.query('insert into tilitapahtuma (idKortti, aikaleima, tapahtuma, summa) values(?,NOW(),?,?)',
      [tilitapahtuma.idKortti, tilitapahtuma.tapahtuma, tilitapahtuma.summa], callback)
  },
  delete: function (id, callback) {                                               //Voihan tätä käyttää tapahtumien peruuttamiseen
    return db.query('delete from tilitapahtuma where id=?', [id], callback)
  },
  update: function (id, tilitapahtuma, callback) {                                //Tämä ei tule näkymään loppukäyttäjälle
    return db.query('update tilitapahtuma set idKortti=?, aikaleima=NOW(), tapahtuma=?, summa=? where id=?',
      [tilitapahtuma.idKortti, tilitapahtuma.tapahtuma, tilitapahtuma.summa, id], callback)
  }
}

module.exports = tilitapahtuma