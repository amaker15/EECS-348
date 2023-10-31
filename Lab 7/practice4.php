<?php
if(isset($_GET['num']) && !empty($_GET['num'])) {
    $num = $_GET['num'];
    echo "<table border='1' cellspacing='0' cellpadding='5'>";

    for($i = 1; $i <= $num; $i++) {
        echo "<tr>";
        for($j = 1; $j <= $num; $j++) {
            echo "<td>". $i*$j ."</td>";
        }
        echo "</tr>";
    }
    echo "</table>";
} else {
    echo "
    <form method='GET'>
      <input type='number' name='num' placeholder='Enter a number'>
      <button type='submit'>Submit</button>
    </form>
  ";
}
?>

