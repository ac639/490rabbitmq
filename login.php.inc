k<?php

class loginDB
{
private $logindb;

public function __construct()
{
        $this->logindb = new mysqli("127.0.0.1","root","password","490db");

        if ($this->logindb->connect_errno != 0)
        {
                echo "Error connecting to database: ".$this->logindb->connect_error.PHP_EOL;
                exit(1);
        }
        echo "correctly connected to database".PHP_EOL;
}

public function validateLogin($username,$password)
{
        $un = $this->logindb->real_escape_string($username);
        $pw = $this->logindb->real_escape_string($password);
        $statement = "select * from users where screenname = '$un'";
        $response = $this->logindb->query($statement);

        while ($row = $response->fetch_assoc())
        {
                echo "Check if $un in db";
                if ($row["username"] == $un)
                {        echo "$un found in database";

                } else
                {
                        echo "$un not found in database!";
                }

                echo "Check if password matches for $username".PHP_EOL;
                
		if ($row["password"] == $pw) {
                        echo "Password matches for $username".PHP_EOL;
                        return 1;
                }
                echo "Password does not match for $username".PHP_EOL;
        }
        return 0;//no users matched username
}
}
?>





