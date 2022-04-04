const db = require('../database')

//Aikaleiman muoto on YYYY-MM-DDTHH:MM:SS.000Z

const tilitapahtuma = {
  get: function (callback) {
    return db.query('select * from tilitapahtuma', callback)                     //Haetaan kaikki tapahtumat listausta varten
  },
  getByTili: function (idKortti, callback) {                                     //Haetaan kaikki korttiin liittyvät tapahtumat esittämistä varten
    return db.query('select * from tilitapahtuma where idKortti=? inner join kortti on tilitapahtuma.idKortti = kortti.id',
    [idKortti], callback)
  },
  getByAikaleima: function (aikaleima, idKortti, callback) {                      //Haetaan yksittäinen tapahtuma aikaleiman mukaan
    return db.query('select * from tilitapahtuma where aikaleima=? and idKortti=? inner join kortti on tilitapahtuma.idKortti = kortti.id', 
    [aikaleima, idKortti], callback)
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