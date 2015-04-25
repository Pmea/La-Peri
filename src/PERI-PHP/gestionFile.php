<?php

function getAllValues($path){
	$fp = fopen($path, "r");

	if (flock($fp, LOCK_SH)) {
		$xml = simplexml_load_file($path);
		flock($fp, LOCK_UN);
	}
	$tab = array();
	
	if(sizeof($xml) >= 259200)
		$taille = sizeof($xml)-259200;
	else
		$taille = 0;

	for($i = sizeof($xml)-1; $i > $taille; $i--){
		$last = $xml->timestamp[$i];
		$res = $last['valeur'].' '.$last->temperature.' '.$last->humidite.' '.$last->luminosite;
		array_push($tab, $res);
	}
	return $tab;
}

/* Recupere la valeur a du dernier timestamp */
function getLastValue($path){
	$fp = fopen($path, "r");
	
	if (flock($fp, LOCK_SH)) {
		$xml = simplexml_load_file($path);
		flock($fp, LOCK_UN);
		
		$taille = sizeof($xml);
		
		$last = $xml->timestamp[$taille-1];	
	}
	
	return $last['valeur'].' '.$last->temperature.' '.$last->humidite.' '.$last->luminosite;
}

function php2js ($var) {
    if (is_array($var)) {
        $res = "[";
        $array = array();
        foreach ($var as $a_var) {
            $array[] = php2js($a_var);
        }
        return "[" . join(",", $array) . "]";
    }
    elseif (is_bool($var)) {
        return $var ? "true" : "false";
    }
    elseif (is_int($var) || is_integer($var) || is_double($var) || is_float($var)) {
        return $var;
    }
    elseif (is_string($var)) {
        return "\"" . addslashes(stripslashes($var)) . "\"";
    }
    // autres cas: objets, on ne les gère pas
    return FALSE;
}
?>