#ifndef DLLRESTAPI_H
#define DLLRESTAPI_H

#include "DLLRestAPI_global.h"
#include <QObject>
#include <QJsonArray>
#include "restapiengine.h"

/*!
 * \brief The DLLRestAPI class for communicating with BankSimul Node Express REST API
 */
class DLLRESTAPI_EXPORT DLLRestAPI : public QObject
{
    Q_OBJECT
public:
    /*!
     * \brief DLLRestAPI constructor
     * \param baseUrl e.g. "http://localhost:3000/"
     */
    DLLRestAPI(QString baseUrl);
    ~DLLRestAPI();

private:
   RestAPIEngine *pRestAPIEngine;
   QString cardNumber;

signals:
   /*!
    * \brief toExeLoginProcessedSignal
    * \param result has fields "token" and "result" if result is succesful. Otherwise it has field "error" which explains the error with message.
    */
   void toExeLoginProcessedSignal(QJsonObject result);

   /*!
    * \brief toExeLogoutProcessedSignal
    * \param result has field "result" if result is succesful. Otherwise it has field "error" which explains the error with message.
    */
   void toExeLogoutProcessedSignal(QJsonObject result);

   /*!
    * \brief toExeGetAccTransactsProcessedSignal
    * \param result has field "result" if result is succesful. Otherwise it has field "error" which explains the error with message.
    */
   void toExeGetAccTransactsProcessedSignal(QJsonObject result);

   /*!
    * \brief toExeGetAccBalanceProcessedSignal
    * \param result has field "result" if result is succesful. Otherwise it has field "error" which explains the error with message.
    */
   void toExeGetAccBalanceProcessedSignal(QJsonObject result);

   /*!
    * \brief toExeGetCustCardsProcessedSignal
    * \param result has field "result" if result is succesful. Otherwise it has field "error" which explains the error with message.
    */
   void toExeGetCustCardsProcessedSignal(QJsonObject result);

   /*!
    * \brief toExeWithdrawProcessedSignal
    * \param result has field "result" if result is succesful. Otherwise it has field "error" which explains the error with message.
    */
   void toExeWithdrawProcessedSignal(QJsonObject result);

   /*!
    * \brief toExeTransactProcessedSignal
    * \param result has field "result" if result is succesful. Otherwise it has field "error" which explains the error with message.
    */
   void toExeTransactProcessedSignal(QJsonObject result);

   /*!
    * \brief toExeLockCardProcessedSignal
    * \param result has field "result" if result is succesful. Otherwise it has field "error" which explains the error with message.
    */
   void toExeLockCardProcessedSignal(QJsonObject result);

public slots:
   /*!
    * \brief fromExeLoginSlot starts login process. Result is send back with toExeLoginProcessedSignal as a QJsonObject.
    * \param cardNumber max 16 chars
    * \param pinCode max 4 numbers
    */
   void fromExeLoginSlot(QString cardNumber, QString pinCode);

   /*!
    * \brief fromExeLogoutSlot starts logout process.
    */
   void fromExeLogoutSlot();

   /*!
    * \brief fromExeGetAccTransactsSlot starts transaction retrieval process. Result is send back with toExeGetAccTransactsProcessedSignal as a QJsonObject.
    * \param offset number of which row is the starting point. For batch like retrieval increase offset e.g. by 10 every call.
    * \param noOfRows number of transaction rows to be retrieved.
    */
   void fromExeGetAccTransactsSlot(int offset, int noOfRows);

   /*!
    * \brief fromExeGetAccBalanceSlot starts balance retrieval process. Result is send back with toExeGetAccBalanceProcessedSignal as a QJsonObject.
    */
   void fromExeGetAccBalanceSlot();

   /*!
    * \brief fromExeGetCustCardsSlot starts customers cards and balances retrieval process. Result is send back with toExeGetCustCardsProcessedSignal as a QJsonObject.
    */
   void fromExeGetCustCardsSlot();

   /*!
    * \brief fromExeWithdrawSlot starts withdraw process. Result is send back with toExeWithdrawProcessedSignal as a QJsonObject.
    * \param amount to withdraw
    */
   void fromExeWithdrawSlot(double amount);

   /*!
    * \brief fromExeTransactSlot starts transaction process. Result is send back with toExeTransactProcessedSignal as a QJsonObject.
    * \param amount to transfer
    * \param targetCardNumber target of transfer
    */
   void fromExeTransactSlot(double amount, QString targetCardNumber);

   /*!
    * \brief fromExeLockCardSlot starts ATM card locking process. Result is send back with toExeLockCardProcessedSignal as a QJsonObject.
    */
   void fromExeLockCardSlot();

   // private slots handle inner communication of dll
private slots:
   void fromEngineLoginProcessedSlot(QJsonObject result);
   void fromEngineGetAccTransactsProcessedSlot(QJsonObject result);
   void fromEngineGetAccBalanceProcessedSlot(QJsonObject result);
   void fromEngineGetCustCardsProcessedSlot(QJsonObject result);
   void fromEngineWithdrawProcessedSlot(QJsonObject result);
   void fromEngineTransactProcessedSlot(QJsonObject result);
   void fromEngineLockCardProcessedSlot(QJsonObject result);
};

#endif // DLLRESTAPI_H
