-- phpMyAdmin SQL Dump
-- version 4.8.3
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Jun 19, 2019 at 10:46 AM
-- Server version: 10.1.35-MariaDB
-- PHP Version: 7.2.9

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `techno`
--

-- --------------------------------------------------------

--
-- Table structure for table `berita`
--

CREATE TABLE `berita` (
  `idBerita` int(45) NOT NULL,
  `Gambar` text NOT NULL,
  `JudulBerita` varchar(400) NOT NULL,
  `IsiBerita` text NOT NULL,
  `Tag` text NOT NULL,
  `DateMulai` date NOT NULL,
  `DateSelesai` date NOT NULL,
  `TimeMulai` time NOT NULL,
  `TimeSelesai` time NOT NULL,
  `TimeStamp` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `berita`
--

INSERT INTO `berita` (`idBerita`, `Gambar`, `JudulBerita`, `IsiBerita`, `Tag`, `DateMulai`, `DateSelesai`, `TimeMulai`, `TimeSelesai`, `TimeStamp`) VALUES
(1, '00c.jpg', 'Berita 1', 'Ini adalah berita ini adalah berita', 'Berita', '2019-05-13', '2019-05-12', '08:00:00', '12:00:00', '2019-05-13 09:18:30'),
(2, '00C.JPG', 'Berita 2', 'Ini adalah berita ini adalah berita', 'Berita', '2019-05-12', '2019-05-12', '08:00:00', '12:00:00', '2019-05-13 09:27:15'),
(7, 'photo_2019-02-11_13-44-21.jpg', 'Tessss', 'wqeqweqweqw', 'aaaaaaaaaaaaaaaaaaaadasdsadnnkslhlskdflkasfnalknd', '2019-06-12', '2019-06-23', '12:31:00', '00:31:00', '2019-06-01 05:41:23');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `berita`
--
ALTER TABLE `berita`
  ADD PRIMARY KEY (`idBerita`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `berita`
--
ALTER TABLE `berita`
  MODIFY `idBerita` int(45) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=8;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
