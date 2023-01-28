<?php

 include('connect.php');
$Vardas=$_POST['Vardas'];
$Pavarde=$_POST['Pavarde'];
$Miestas=$_POST['Miestas'];
$Amzius=$_POST['Amzius'];
$Gimimo_data=$_POST['Gimimo_data'];

$sql = "INSERT INTO Zmogus (Vardas, Pavarde, Miestas, Amzius, Gimimo_data) VALUES ('$Vardas', '$Pavarde', '$Miestas', '$Amzius', '$Gimimo_data');";
if ($conn->multi_query($sql) === TRUE) {
 echo "Sukurti nauji duomenys";
 
} else {
 echo "Klaida kuriant naujus duomenis: " . $sql . "<br>" . $conn->error;
}

?>