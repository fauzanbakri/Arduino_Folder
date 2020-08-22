-- phpMyAdmin SQL Dump
-- version 4.5.1
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1
-- Generation Time: Jan 05, 2019 at 04:50 PM
-- Server version: 10.1.16-MariaDB
-- PHP Version: 7.0.9

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `a`
--

-- --------------------------------------------------------

--
-- Table structure for table `date_time`
--

CREATE TABLE `date_time` (
  `id_dt` int(11) NOT NULL,
  `time` time NOT NULL,
  `ulang` varchar(50) NOT NULL,
  `tanggal` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `keuangan`
--

CREATE TABLE `keuangan` (
  `id_uang` varchar(10) NOT NULL,
  `nominal` decimal(10,0) NOT NULL,
  `biaya` decimal(10,0) NOT NULL,
  `expire` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `lokasi`
--

CREATE TABLE `lokasi` (
  `id_lokasi` varchar(10) NOT NULL,
  `username` varchar(100) NOT NULL,
  `nama_lokasi` char(200) NOT NULL,
  `latitude` int(11) NOT NULL,
  `longitude` int(11) NOT NULL,
  `suggest` char(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `memo`
--

CREATE TABLE `memo` (
  `id_judul` int(11) NOT NULL,
  `judul` char(20) NOT NULL,
  `aktifitas` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `pinmoney`
--

CREATE TABLE `pinmoney` (
  `id_history` int(10) NOT NULL,
  `aktivitas` varchar(100) NOT NULL,
  `tanggal` date NOT NULL,
  `biaya` decimal(10,0) NOT NULL,
  `ket` varchar(200) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `profile`
--

CREATE TABLE `profile` (
  `id_profil` int(11) NOT NULL,
  `username` varchar(30) NOT NULL,
  `tgl_lahir` date NOT NULL,
  `gender` char(10) NOT NULL,
  `phone` char(13) NOT NULL,
  `alamat` char(250) NOT NULL,
  `about` varchar(300) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `profile`
--

INSERT INTO `profile` (`id_profil`, `username`, `tgl_lahir`, `gender`, `phone`, `alamat`, `about`) VALUES
(1, 'fauzan', '2019-01-01', 'L', '080808', 'alamat', 'about');

-- --------------------------------------------------------

--
-- Table structure for table `user_login`
--

CREATE TABLE `user_login` (
  `id_user` int(11) NOT NULL,
  `nama` char(50) NOT NULL,
  `email` char(25) NOT NULL,
  `username` char(20) NOT NULL,
  `password` char(10) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `user_login`
--

INSERT INTO `user_login` (`id_user`, `nama`, `email`, `username`, `password`) VALUES
(1, 'hikmah', 'hikmahdwi9@gmail.com', 'hikmahnasir', 'hikmah'),
(2, 'Hikmah Dwiyanti', 'hikmahdwi9@gmail.com', 'hikmahdwi', '123456'),
(3, 'ajri', 'ajri@gmail', 'nurfajriani', '12345'),
(6, 'wiwi', 'wiwi@gmail.com', 'wiwi', '1234'),
(7, 'umi', 'umi@gmail.com', 'umi', '1234'),
(9, 'atun', 'atun', 'atun', 'atun'),
(18, 'unna', 'unna@gmail', 'unna', 'unna'),
(19, 'nama', 'mail@mail.com', 'username', 'username');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `date_time`
--
ALTER TABLE `date_time`
  ADD PRIMARY KEY (`id_dt`);

--
-- Indexes for table `memo`
--
ALTER TABLE `memo`
  ADD PRIMARY KEY (`id_judul`);

--
-- Indexes for table `profile`
--
ALTER TABLE `profile`
  ADD PRIMARY KEY (`id_profil`),
  ADD UNIQUE KEY `username` (`username`);

--
-- Indexes for table `user_login`
--
ALTER TABLE `user_login`
  ADD PRIMARY KEY (`id_user`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `date_time`
--
ALTER TABLE `date_time`
  MODIFY `id_dt` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `memo`
--
ALTER TABLE `memo`
  MODIFY `id_judul` int(11) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `user_login`
--
ALTER TABLE `user_login`
  MODIFY `id_user` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=20;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
