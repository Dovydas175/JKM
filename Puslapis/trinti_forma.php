
<form action="red_db_saugoti.php" method="POST">

<html>
    <head>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-EVSTQN3/azprG1Anm3QDgpJLIm9Nao0Yz1ztcQTwFspd3yD65VohhpuuCOmLASjC" crossorigin="anonymous">
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js" integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM" crossorigin="anonymous"></script>
</head>

<body>

<?php

$irs_ID=$_GET['IID'];

include('connect.php');

$sql = "DELETE FROM Zmogus WHERE id=$irs_ID";
if ($conn->query($sql) === TRUE) {
    echo " ";
} else {
    echo "Klaida trinant duomenis: " . $sql . "<br>" . $conn->error;
}
$conn->close();


?>

</body>