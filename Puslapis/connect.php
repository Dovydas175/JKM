<?php


$servername = "localhost";
$username = "PG00125AB";
$password = "jkm_PG00125AB";
$dbname = "PG00125AB";
$conn = new mysqli($servername, $username, $password, $dbname);
// Check connection
if ($conn->connect_error) {
 die("Connection failed: " . $conn->connect_error);
}
echo " "; //Connected successfully

?>