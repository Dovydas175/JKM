<html>
    <head>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-EVSTQN3/azprG1Anm3QDgpJLIm9Nao0Yz1ztcQTwFspd3yD65VohhpuuCOmLASjC" crossorigin="anonymous">
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js" integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM" crossorigin="anonymous"></script>
</head>


<body>
<table class="table">
    <thead>
        <tr>
            <th>Markė</th>
            <th>Valstybinis Nr</th>
            <th>Pagaminimo data</th>
            <th>Draudimas</th>
            <th>Kategorija</th>
            <th>Modelis</th>
            <th>Žiūrėti</th>
        </tr>
    </thead>
    <tbody>

<?php
include('connect.php');

$sql = "SELECT * FROM Automobiliai";
$result = $conn->query($sql);
if ($result->num_rows > 0) {
 // output data of each row
 while($row = $result->fetch_assoc()) {
 echo "<tr><td>" . $row["Markė"]. "</td><td>" . $row["Valstybinis_Nr"]. "</td><td>" . $row["Pagaminimo_data"]. "</td><td>" . $row["Draudimas"]. "</td><td>" . $row["Kategorija"]. "</td><td>" . $row["Modelis"].
 "</td><td> <a href='marsrutai_ziuret.php?IID=".$row["ID"]."' class = 'btn btn-primary'>Žiūrėti</a></td>";
}
} else {
 echo "0 results";
}
$conn->close();

?>
    </tbody>
</table>
</body>
