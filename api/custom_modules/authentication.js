const jwt = require('jsonwebtoken');

function authenticateToken(req, res, next) {

    // Extract token from header
    const authHeader = req.headers['authorization']
    const token = authHeader && authHeader.split(' ')[1]
    console.log("token = "+token);
    
    // Return error if token is null
    if (!token) return res.status(401).send( {error: "Unauthorized access. Token is null"} );


    jwt.verify(token, process.env.MY_TOKEN, (err, decodedToken) => {  
      // Return error if token does not match cardnumber
      if (err || req.body.cardNumber !== decodedToken.cardNumber) return res.status(403).send( {error: "Unauthorized access. Token is invalid"} );
      next()
    })
  }

  module.exports = authenticateToken;