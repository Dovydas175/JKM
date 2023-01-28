<html>
    <head>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-EVSTQN3/azprG1Anm3QDgpJLIm9Nao0Yz1ztcQTwFspd3yD65VohhpuuCOmLASjC" crossorigin="anonymous">
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js" integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM" crossorigin="anonymous"></script>
</head>


<body>
<table class="table">
    <thead>
        <tr>
            <th>Vardas</th>
            <th>Pavarde</th>
            <th>Miestas</th>
            <th>Redaguoti</th>
            <th>Trinti</th>
        </tr>
    </thead>
    <tbody>

<?php
include('connect.php');

$sql = "SELECT * FROM Zmogus";
$result = $conn->query($sql);
if ($result->num_rows > 0) {
 // output data of each row
 while($row = $result->fetch_assoc()) {
 echo "<tr><td>" . $row["Vardas"]. "</td><td>" . $row["Pavarde"]. "</td><td>" . $row["Miestas"].
 "</td><td> <a href='red_forma.php?IID=".$row["ID"]."' class = 'btn btn-primary'>Redaguoti</a></td>".
 "<td><a href='trinti_forma.php?IID=".$row["ID"]."' class = 'btn btn-secondary'>Trinti</a></td></tr>";
 }
} else {
 echo "0 results";
}
$conn->close();

?>
    </tbody>
</table>
</body>
