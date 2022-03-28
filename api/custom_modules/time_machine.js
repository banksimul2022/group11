//Tässä moduulissa tehdään timestamp tilitietoja varten

const time_machine = {
    TIMESTAMP : function() {
        let event = new Date().toLocaleDateString()
        let moment = new Date().toLocaleTimeString()

        return event, moment
    }
}

module.exports = time_machine