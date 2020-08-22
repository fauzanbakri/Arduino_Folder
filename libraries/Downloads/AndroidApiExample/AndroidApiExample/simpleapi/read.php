<?php
	header("Content-Type: application/json; charset=UTF-8");
	// $obj = json_decode($_GET["x"], false);
	
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

    // membuat query
    $sql = "SELECT * FROM mahasiswa";
    // lakukan eksekusi query
    $result = $conn->query($sql);

    // simpan hasil dalam array
    $rows = array();
	while($r = mysqli_fetch_assoc($result)) {
	    $rows[] = $r;
	}

	// kembalikan dalam bentuk json
	print json_encode($rows);
?>