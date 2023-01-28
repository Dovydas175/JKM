<?php

include('connect.php');

$ID=$_POST['ID_line'];
$Vardas=$_POST['vardas_new'];
$Pavarde=$_POST['pavarde_new'];
$Miestas=$_POST['miestas_new'];
$Amzius=$_POST['amzius_new'];
$Gimimo_data=$_POST['gimimo_data_new'];

$sql = "UPDATE Zmogus SET Vardas='$Vardas', Pavarde='$Pavarde', Miestas='$Miestas', Amzius='$Amzius', Gimimo_data='$Gimimo_data' WHERE id='$ID'";
if ($conn->query($sql) === TRUE) {
 echo " ";
} else {
 echo "Error updating record: " . $sql . "<br>" . $conn->error;
}
$conn->close();

?>