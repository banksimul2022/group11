const db = require('../database')
const aikakone = require('../custom_modules/time_machine')                        //Tämä kone hallitsee aikaa ja aikaleimoja

//Jos tilipahtuma id ei ole autoincrement niin tähän koodi tarkastamaan tapahtumanumerot

//Tarviiko deleteById & deleteByAikaleima

//Also pitäskö kääntää nämä kaikki tiedostot to english

const tilitapahtumat = {
  get: function (callback) {
    return db.query('select * from tilitapahtumat', callback);                    //Haetaan kaikki tapahtumat listausta varten
  },
  getByAikaleima: function (aikaleima, callback) {                                //Haetaan yksittäinen tapahtuma aikaleiman mukaan
    return db.query('select * from tilitapahtumat where aikaleima=?', [aikaleima], callback);
  },
  getById: function (id, callback) {                                              //Haetaan yksittäinen tapahtuma id:n mukaan
    return db.query('select * from tilitapahtumat where id=?', [id], callback);
  },
  add: function (tilitapahtumat, callback) {                                      //Tässä operaatio jos asiakas nostaa, lisää tai siirtää rahaa
    return db.query('insert into tilitapahtumat (idKortti, aikaleima, tapahtuma, summa) values(?,?,?,?)',
      [tilitapahtumat.idKortti, aikakone.TIMESTAMP, tilitapahtumat.tapahtuma, tilitapahtumat.summa], callback);
  },
  delete: function (id, callback) {
    return db.query('delete from tilitapahtumat where id=?', [id], callback);
  },
  update: function (id, tilitapahtumat, callback) {                               //Tämä ei tule näkymään loppukäyttäjälle
    return db.query('update tilitapahtumat set idKortti=?, aikaleima=?, tapahtuma=?, summa=? where id=?',
      [tilitapahtumat.idKortti, aikakone.TIMESTAMP, tilitapahtumat.tapahtuma, tilitapahtumat.summa, id], callback);
  }
}

module.exports = tilitapahtumat;