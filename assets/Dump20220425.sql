CREATE DATABASE  IF NOT EXISTS `heroku_aa383b216a9c7f7` /*!40100 DEFAULT CHARACTER SET utf8 */ /*!80016 DEFAULT ENCRYPTION='N' */;
USE `heroku_aa383b216a9c7f7`;
-- MySQL dump 10.13  Distrib 8.0.28, for Win64 (x86_64)
--
-- Host: 127.0.0.1    Database: heroku_aa383b216a9c7f7
-- ------------------------------------------------------
-- Server version	8.0.23

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `asiakas`
--

DROP TABLE IF EXISTS `asiakas`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `asiakas` (
  `id` int NOT NULL AUTO_INCREMENT,
  `tunnus` varchar(20) NOT NULL,
  `etunimi` varchar(20) NOT NULL,
  `sukunimi` varchar(20) NOT NULL,
  `osoite` varchar(50) NOT NULL,
  `puhelin` varchar(20) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `asiakastili`
--

DROP TABLE IF EXISTS `asiakastili`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `asiakastili` (
  `id` int NOT NULL AUTO_INCREMENT,
  `idAsiakas` int NOT NULL,
  `idTili` int NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  KEY `idAsiakas_idx` (`idAsiakas`),
  KEY `idTili_idx` (`idTili`),
  CONSTRAINT `idAsiakas` FOREIGN KEY (`idAsiakas`) REFERENCES `asiakas` (`id`),
  CONSTRAINT `idTili` FOREIGN KEY (`idTili`) REFERENCES `tili` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=32 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `kortti`
--

DROP TABLE IF EXISTS `kortti`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `kortti` (
  `id` int NOT NULL AUTO_INCREMENT,
  `idAsiakasTili` int NOT NULL,
  `korttiNumero` varchar(16) NOT NULL,
  `pinKoodi` varchar(255) NOT NULL,
  `lukittu` tinyint NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  UNIQUE KEY `korttiNumero_UNIQUE` (`korttiNumero`),
  KEY `idAsiakasTili_idx` (`idAsiakasTili`),
  CONSTRAINT `idAsiakasTili` FOREIGN KEY (`idAsiakasTili`) REFERENCES `asiakastili` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=33 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `tili`
--

DROP TABLE IF EXISTS `tili`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `tili` (
  `id` int NOT NULL AUTO_INCREMENT,
  `tilinumero` varchar(18) NOT NULL,
  `saldo` decimal(16,2) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  UNIQUE KEY `tilinumero_UNIQUE` (`tilinumero`)
) ENGINE=InnoDB AUTO_INCREMENT=33 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `tilitapahtuma`
--

DROP TABLE IF EXISTS `tilitapahtuma`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `tilitapahtuma` (
  `id` int NOT NULL AUTO_INCREMENT,
  `idKortti` int NOT NULL,
  `aikaleima` datetime NOT NULL,
  `tapahtuma` varchar(10) NOT NULL,
  `summa` decimal(16,2) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `id_UNIQUE` (`id`),
  KEY `idKortti_idx` (`idKortti`),
  CONSTRAINT `idKortti` FOREIGN KEY (`idKortti`) REFERENCES `kortti` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=162 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping routines for database 'heroku_aa383b216a9c7f7'
--
/*!50003 DROP PROCEDURE IF EXISTS `sp_AvaaLukitseKortti` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8 */ ;
/*!50003 SET character_set_results = utf8 */ ;
/*!50003 SET collation_connection  = utf8_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'NO_AUTO_VALUE_ON_ZERO' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `sp_AvaaLukitseKortti`(p_korttiNumero VARCHAR(16), p_lukitusTila TINYINT)
BEGIN
	# Luo lukituksen tilan statusteksti tilitapahtumia varten
	DECLARE _lukitusStatus VARCHAR(10);
    IF p_lukitusTila = 1 THEN
		SET _lukitusStatus = 'LUKITTU';
	ELSE SET _lukitusStatus = 'AVATTU';
    END IF;
	
	# Lukitse/avaa kortti ja tee merkintä tilitapahtumiin
	UPDATE kortti
	SET lukittu = p_lukitusTila
	WHERE korttiNumero = p_korttiNumero;
	CALL sp_LisaaTilitapahtuma(p_korttiNumero, _lukitusStatus, 0);
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `sp_Debug` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8 */ ;
/*!50003 SET character_set_results = utf8 */ ;
/*!50003 SET collation_connection  = utf8_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'NO_AUTO_VALUE_ON_ZERO' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `sp_Debug`(enabled INTEGER, msg VARCHAR(255))
BEGIN
  IF enabled THEN
    select concat('** ', msg) AS '** DEBUG:';
  END IF;
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `sp_HaeKortinOmistajanKortit` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8 */ ;
/*!50003 SET character_set_results = utf8 */ ;
/*!50003 SET collation_connection  = utf8_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'NO_AUTO_VALUE_ON_ZERO' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `sp_HaeKortinOmistajanKortit`(p_korttiNumero VARCHAR(16))
BEGIN
	# Haetaan ensin kortin omistajan id asiakas-taulusta
	DECLARE _asiakasId INT;
    SELECT asiakas.id INTO _asiakasId FROM asiakas
    INNER JOIN asiakastili
    ON asiakas.id = asiakastili.idAsiakas
    INNER JOIN kortti
    ON asiakastili.id = kortti.idAsiakasTili
    WHERE kortti.korttiNumero = p_korttiNumero;
    
    # Haetaan asiakkaan kortit
    SELECT asiakas.etunimi, asiakas.sukunimi, kortti.korttiNumero as korttinumero, tili.tilinumero, tili.saldo FROM tili, asiakas
    INNER JOIN asiakastili
    ON asiakas.id = asiakastili.idAsiakas
    INNER JOIN kortti
    ON kortti.idAsiakasTili = asiakastili.id
    WHERE asiakas.id = _asiakasId AND tili.id = asiakastili.idTili;
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `sp_HaeSaldo` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8 */ ;
/*!50003 SET character_set_results = utf8 */ ;
/*!50003 SET collation_connection  = utf8_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'NO_AUTO_VALUE_ON_ZERO' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `sp_HaeSaldo`(p_korttiNumero VARCHAR(16))
BEGIN    
	# Etsi tilinumero joka sopii korttiin
	DECLARE _tilinumero VARCHAR(18);
    CALL sp_HaeTiliKorttinumerolla(p_korttiNumero, _tilinumero);

	SELECT saldo FROM tili
    WHERE tilinumero = _tilinumero;
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `sp_HaeTiliKorttinumerolla` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8 */ ;
/*!50003 SET character_set_results = utf8 */ ;
/*!50003 SET collation_connection  = utf8_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'NO_AUTO_VALUE_ON_ZERO' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `sp_HaeTiliKorttinumerolla`(p_korttiNumero VARCHAR(16), OUT out_tilinumero VARCHAR(18))
BEGIN
	SELECT tilinumero INTO out_tilinumero FROM tili
    JOIN asiakasTili
    ON tili.id = asiakasTili.idTili
    JOIN kortti
    ON asiakasTili.id = kortti.idAsiakasTili
    WHERE kortti.korttiNumero = p_korttiNumero;
    #CALL sp_Debug(TRUE, out_tilinumero);
    IF out_tilinumero IS NULL THEN
		SIGNAL SQLSTATE '45000'
		SET MESSAGE_TEXT = 'ERROR: Cardnumber not connected to account';
    END IF;
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `sp_HaeTilitapahtumat` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8 */ ;
/*!50003 SET character_set_results = utf8 */ ;
/*!50003 SET collation_connection  = utf8_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'NO_AUTO_VALUE_ON_ZERO' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `sp_HaeTilitapahtumat`(p_korttiNumero VARCHAR(16), p_alkaenRiviNumero INT, p_tulostenMaara INT)
BEGIN
	# Etsi tilinumero joka sopii korttiin
	DECLARE _tilinumero VARCHAR(18);
    CALL sp_HaeTiliKorttinumerolla(p_korttiNumero, _tilinumero);

    # Etsi kaikki tilitapahtumat edellä etsitylle tilille kahdessa select lauseessa, jotka yhdistetään idAsiakasTili-tunnuksella.
	SELECT etunimi, sukunimi, tilinumero, aikaleima, tapahtuma, summa FROM 
    (
	SELECT asiakasTili.id as idAsiakasTili, etunimi, sukunimi, tilinumero FROM asiakas
	INNER JOIN asiakasTili
	ON asiakas.id = asiakasTili.idAsiakas
	INNER JOIN tili
	on tili.id = asiakasTili.idTili
    ) AS Q1
	INNER JOIN 
    (
	SELECT idAsiakasTili, korttiNumero, aikaleima, tapahtuma, summa FROM kortti 
	INNER JOIN tilitapahtuma
	ON kortti.id = tilitapahtuma.idKortti
    ) AS Q2
	ON Q1.idAsiakasTili = Q2.idAsiakasTili
    WHERE tilinumero = _tilinumero 
    ORDER BY aikaleima DESC
    LIMIT p_alkaenRiviNumero, p_tulostenMaara;
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `sp_LisaaTilitapahtuma` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8 */ ;
/*!50003 SET character_set_results = utf8 */ ;
/*!50003 SET collation_connection  = utf8_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'NO_AUTO_VALUE_ON_ZERO' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `sp_LisaaTilitapahtuma`(p_korttiNumero VARCHAR(16), p_tapahtuma VARCHAR(10), p_summa DECIMAL(16,2))
BEGIN
	DECLARE _korttiId INT;
    
    # Etsi kortin id
    SELECT id INTO _korttiId FROM kortti
    WHERE kortti.korttiNumero = p_korttiNumero;
    
    # Syötä tapahtuma tilitapahtuma-tauluun
    INSERT INTO tilitapahtuma (idKortti, aikaleima, tapahtuma, summa) 
    VALUE (_korttiId, NOW(), p_tapahtuma, p_summa);    
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `sp_LukitseKortti` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8 */ ;
/*!50003 SET character_set_results = utf8 */ ;
/*!50003 SET collation_connection  = utf8_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'NO_AUTO_VALUE_ON_ZERO' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `sp_LukitseKortti`(korttiNumero VARCHAR(16))
BEGIN
	# Lukitse kortti
	UPDATE kortti
	SET lukittu = 1
	WHERE korttiNumero = korttiNumero;
	CALL sp_LisaaTilitapahtuma(korttiNumero, 'LUKITTU', 0);
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `sp_NostaRahaa` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8 */ ;
/*!50003 SET character_set_results = utf8 */ ;
/*!50003 SET collation_connection  = utf8_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'NO_AUTO_VALUE_ON_ZERO' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `sp_NostaRahaa`(p_korttiNumero VARCHAR(16), p_nostettavaMaara DECIMAL(16,2))
BEGIN
	# Paikalliset muuttujat
	DECLARE _tilinumero VARCHAR(18);
    DECLARE _saldo DECIMAL(16,2);
    
    # Etsi tilinumero joka sopii korttiin
	CALL sp_HaeTiliKorttinumerolla(p_korttiNumero, _tilinumero);    
	
	# Heitä virhe jos ei tarpeeksi rahaa tilillä    
    SELECT saldo INTO _saldo FROM tili WHERE tilinumero = _tilinumero;
	IF _saldo < p_nostettavaMaara THEN
		SIGNAL SQLSTATE '45000'
		SET MESSAGE_TEXT = 'ERROR: Withdraw amount exceeds account balance';
	END IF;
	
	# Hae tilin tiedot tilinumerolla
	UPDATE tili
	SET saldo = (saldo - p_nostettavaMaara)
	WHERE tilinumero = _tilinumero;
	CALL sp_LisaaTilitapahtuma(p_korttiNumero, 'NOSTO', -p_nostettavaMaara);
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `sp_SiirraRahaa` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8 */ ;
/*!50003 SET character_set_results = utf8 */ ;
/*!50003 SET collation_connection  = utf8_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'NO_AUTO_VALUE_ON_ZERO' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `sp_SiirraRahaa`(p_korttiNumero VARCHAR(16), p_siirrettavaMaara DECIMAL(16,2), p_kohdeKorttiNumero VARCHAR(18))
BEGIN
	# Paikalliset muuttujat
	DECLARE _tilinumero VARCHAR(18);
    DECLARE _kohdeTilinumero VARCHAR(18);
    DECLARE _saldo DECIMAL(16,2);
    
    # Etsi tilinumerot joka sopivat kortteihin
    CALL sp_HaeTiliKorttinumerolla(p_korttiNumero, _tilinumero);
    CALL sp_HaeTiliKorttinumerolla(p_kohdeKorttiNumero, _kohdeTilinumero);
    
	# Heitä virhe jos ei tarpeeksi rahaa tilillä    
    SELECT saldo INTO _saldo FROM tili WHERE tilinumero = _tilinumero;
	IF _saldo < p_siirrettavaMaara THEN
		SIGNAL SQLSTATE '45000'
		SET MESSAGE_TEXT = 'ERROR: Transfer amount exceeds account balance';
	END IF;
    
    # Vähennä siirrettävältä tililtä rahat
    UPDATE tili
    SET saldo = (saldo - p_siirrettavaMaara)
    WHERE tilinumero = _tilinumero;
    
    # Lisää siirrettävälle tilille rahat
    UPDATE tili
    SET saldo = (saldo + p_siirrettavaMaara)
    WHERE tilinumero = _kohdeTilinumero;
    
    # Lisää tilitapahtumamerkinnät
    CALL sp_LisaaTilitapahtuma(p_korttiNumero, 'SIIRTO', -p_siirrettavaMaara);
    CALL sp_LisaaTilitapahtuma(p_kohdeKorttiNumero, 'SIIRTO', p_siirrettavaMaara);
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2022-04-25 13:00:24
