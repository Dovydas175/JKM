







<body>

<nav class="navbar navbar-expand-sm bg-dark navbar-dark">
<div class="container-fluid">
<u1 class="navbar-nav">
<li class="nav-item">
<a class="nav-link" href="lentele.php">Lentele</a>
</li>
<li class="nav-item">
<a class="nav-link" href="iterpimas.php">Iterpimas</a>
</li>
<li class="nav-item">
<a class="nav-link" href="#">Link</a>
<li>
</il>
</div>
</nav>

<?php
include ("connect.php");

$vardas=$_POST['fname'];
$pavarde=$_POST['lname"];
$adresas=$_POST['addr"];
$data=$_POST['date"];

$sql = "INSERT INTO Zmones (Vardas, Pavarde, Adresas, GimimoData) VALUES ('$vardas', '$pavarde', '$adresas', '$data')";
if ($conn->multi_query($sql) === TRUE) {
echo "<br>Iterpimas buvo sekmingas.";
} else {
	echo "Error: " . $sql . "<br>" . $conn->error;
}

$conn->close();
?>
</body>
</html>