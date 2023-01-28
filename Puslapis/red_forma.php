
<form action="red_db_saugoti.php" method="POST">

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
            <th>Amzius</th>
            <th>Gimimo data</th>
        </tr>
    </thead>
    <tbody>

<?php


$irs_ID=$_GET['IID'];

include('connect.php');

$sql = "SELECT * FROM Zmogus

where ID= '$irs_ID'";

$result = $conn->query($sql);
if ($result->num_rows > 0) {
 // output data of each row
 while($row = $result->fetch_assoc()) {
 echo "<tr><td>

 <input type='hidden' name='ID_line'  value='". $row["ID"]. "'>
 <input type='text' name='vardas_new'  value='". $row["Vardas"]. "'></td><td>
 <input type='text' name='pavarde_new'  value='". $row["Pavarde"]. "'></td><td>
 <input type='text' name='miestas_new'  value='". $row["Miestas"]. "'></td><td>
 <input type='text' name='amzius_new'  value='". $row["Amzius"]. "'></td><td>
 <input type='date' name='gimimo_data_new'  value='". $row["Gimimo_data"]. "'></td><td>";

 }
} else {
 echo "0 results";
}
$conn->close();



?>
<input type="submit" value="Saugoti">
</form>

    </tbody>
</table>
</body>