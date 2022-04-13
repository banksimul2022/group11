const db = require('../database');

const login={
  checkPincode: function(korttiNumero, callback) {
      return db.query('SELECT pinKoodi FROM kortti WHERE korttiNumero = ?',[korttiNumero], callback); 
    }
};
          
module.exports = login;