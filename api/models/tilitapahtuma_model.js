const db = require('../database')
const aikakone = require('../custom_modules/time_machine')                        //Tämä kone hallitsee aikaa ja aikaleimoja

//Jos tilipahtuma id ei ole autoincrement niin tähän koodi tarkastamaan tapahtumanumerot

//Tarviiko deleteById & deleteByAikaleima

//Also pitäskö kääntää nämä kaikki tiedostot to english

const tilitapahtuma = {
  get: function (callback) {
    return db.query('select * from tilitapahtuma', callback);                    //Haetaan kaikki tapahtumat listausta varten
  },
  getByAikaleima: function (aikaleima, callback) {                                //Haetaan yksittäinen tapahtuma aikaleiman mukaan
    return db.query('select * from tilitapahtuma where aikaleima=?', [aikaleima], callback);
  },
  getById: function (id, callback) {                                              //Haetaan yksittäinen tapahtuma id:n mukaan
    return db.query('select * from tilitapahtuma where id=?', [id], callback);
  },
  add: function (tilitapahtuma, callback) {                                      //Tässä operaatio jos asiakas nostaa, lisää tai siirtää rahaa
    return db.query('insert into tilitapahtuma (idKortti, aikaleima, tapahtuma, summa) values(?,?,?,?)',
      [tilitapahtuma.idKortti, aikakone.TIMESTAMP, tilitapahtuma.tapahtuma, tilitapahtuma.summa], callback);
  },
  delete: function (id, callback) {
    return db.query('delete from tilitapahtuma where id=?', [id], callback);
  },
  update: function (id, tilitapahtuma, callback) {                               //Tämä ei tule näkymään loppukäyttäjälle
    return db.query('update tilitapahtuma set idKortti=?, aikaleima=?, tapahtuma=?, summa=? where id=?',
      [tilitapahtuma.idKortti, aikakone.TIMESTAMP, tilitapahtuma.tapahtuma, tilitapahtuma.summa, id], callback);
  }
}

module.exports = tilitapahtuma;