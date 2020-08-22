<?php
	header("Content-Type: application/json; charset=UTF-8");
	$data = json_decode(file_get_contents('php://input'), true);

    $servername = "localhost";
    $username = "root";
    $password = "Adm1nroot";
    $dbnamea = "kemahasiswaan";

    // Create connection
    $conn = new mysqli($servername, $username, $password, $dbnamea);

    // Check connection
    if ($conn->connect_error) {
        die("Connection failed: " . $conn->connect_error);
    }

    $nim = $data['nim'];
    $nama = $data['nama'];
    $alamat = $data['alamat'];

    // membuat query input
    $sql = "INSERT INTO mahasiswa(nim, nama_mhs, alamat, foto) VALUES('$nim', '$nama', '$alamat', 'dummy.jpg')";
    // eksekusi query
    $conn->query($sql);

 //    // membuat query
 //    $sql = "SELECT * FROM mahasiswa";
 //    // lakukan eksekusi query
 //    $result = $conn->query($sql);

 //    // simpan hasil dalam array
 //    $rows = array();
	// while($r = mysqli_fetch_assoc($result)) {
	//     $rows[] = $r;
	// }

	// kembalikan dalam bentuk json
	print json_encode("Sukses");
?>