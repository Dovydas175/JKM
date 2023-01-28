<html>
    <head>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-EVSTQN3/azprG1Anm3QDgpJLIm9Nao0Yz1ztcQTwFspd3yD65VohhpuuCOmLASjC" crossorigin="anonymous">
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js" integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM" crossorigin="anonymous"></script>
</head>

<body>
<table class="table">
    <thead>
        <tr>
            <th>Miestas nuo</th>
            <th>Miestas iki</th>
            <th>Vastybe</th>
            <th>Atstumas</th>
            <th>Laikas</th>
            <th>Data</th>
        </tr>
    </thead>
    <tbody>

<?php

$irs_ID=$_GET['IID'];

include('connect.php');

$sql = "SELECT m.Miestas_nuo, m.Miestas_iki, m.Valstybe, m.Atstumas, m.Laikas, isv.Data from Automobiliai au
join `Išvykos` isv on isv.Automobilis_ID = au.ID
join Marsrutai m on m.ID = isv.Marsrutas_ID
where isv.Automobilis_ID = '$irs_ID'";

$result = $conn->query($sql);
if ($result->num_rows > 0) {
 // output data of each row
 while($row = $result->fetch_assoc()) {
 echo "<tr><td>" 

 . $row["Miestas_nuo"]. "</td><td>"
 . $row["Miestas_iki"]. "</td><td>"
 . $row["Valstybe"]. "</td><td>"
 . $row["Atstumas"]. "</td><td>"
 . $row["Laikas"]. "</td><td>"
 . $row["Data"]. "</td><td>";
 }
} else {
 echo "0 results";
}
$conn->close();



?>