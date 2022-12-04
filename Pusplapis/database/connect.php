<?php


$servername = "localhost";
$username = "PG00206NN";
$password = "jkm_PG00206NN";
$dbname = "PG00206NN";
$conn = new mysqli($servername, $username, $password, $dbname);
// Check connection
if ($conn->connect_error) {
die("Connection failed: " . $conn->connect_error);
}
echo "Prisijungima sekmingas"; //Connected successfully

?>