const db = require('../database')
const aikakone = require('../custom_modules/time_machine')                        //Tämä kone hallitsee aikaa ja aikaleimoja


const tilitapahtumat = {
  get: function (callback) {
    return db.query('select * from tilitapahtumat', callback)                    //Haetaan kaikki tapahtumat listausta varten
  },
  getByTili: function (idKortti, callback) {                                     //Haetaan kaikki korttiin liittyvät tapahtumat esittämistä varten
    return db.query('select * from tilitapahtumat where idKortti=? inner join kortti on tilitapahtumat.idKortti = kortti.id',
    [idKortti], callback)
  },
  getByAikaleima: function (aikaleima, idKortti, callback) {                      //Haetaan yksittäinen tapahtuma aikaleiman mukaan
    return db.query('select * from tilitapahtumat where aikaleima=? and idKortti=? inner join kortti on tilitapahtumat.idKortti = kortti.id', 
    [aikaleima, idKortti], callback)
  },
  getById: function (id, callback) {                                              //Haetaan yksittäinen tapahtuma id:n mukaan
    return db.query('select * from tilitapahtumat where id=?', [id], callback)
  },
  add: function (tilitapahtumat, callback) {                                      //Tässä operaatio jos asiakas nostaa, lisää tai siirtää rahaa
    return db.query('insert into tilitapahtumat (idKortti, aikaleima, tapahtuma, summa) values(?,?,?,?)',
      [tilitapahtumat.idKortti, aikakone.TIMESTAMP, tilitapahtumat.tapahtuma, tilitapahtumat.summa], callback)
  },
  delete: function (id, callback) {                                               //Voihan tätä käyttää tapahtumien peruuttamiseen
    return db.query('delete from tilitapahtumat where id=?', [id], callback)
  },
  update: function (id, tilitapahtumat, callback) {                               //Tämä ei tule näkymään loppukäyttäjälle
    return db.query('update tilitapahtumat set idKortti=?, aikaleima=?, tapahtuma=?, summa=? where id=?',
      [tilitapahtumat.idKortti, aikakone.TIMESTAMP, tilitapahtumat.tapahtuma, tilitapahtumat.summa, id], callback)
  }
}

module.exports = tilitapahtumat