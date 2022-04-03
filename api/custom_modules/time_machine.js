//Tässä moduulissa tehdään timestamp tilitietoja varten

/* Tätä moduulia ei tarvita jos MySQL löyty date now metodi */

const time_machine = {
    TIMESTAMP : function() {
        let event = new Date().toLocaleDateString()
        let moment = new Date().toLocaleTimeString()
        
        return event + "_" + moment
    }
}
console.log(time_machine.TIMESTAMP())                     //testausta varten
module.exports = time_machine