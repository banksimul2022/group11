const jwt = require('jsonwebtoken');


function authenticateToken(req, res, next) {
    const authHeader = req.headers['authorization']
    const token = authHeader && authHeader.split(' ')[1]
  
    console.log("token = "+token);
    if (token == null) return res.status(401).send( {error: "Unauthorized access. Token is null"} );
  
    jwt.verify(token, process.env.MY_TOKEN, (err, user) => {
      console.log(err)
  
      if (err) return res.status(403).send( {error: "Unauthorized access. Token is invalid"} );
  
      req.user = user
      console.log(user);
      next()
    })
  }

  module.exports = authenticateToken;