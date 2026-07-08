<?php
function writeToLog($message) {
    $logfile = fopen("logFile.log", "a");
    
    // Attempt to get a lock and write a message
    if (flock($logfile, LOCK_EX | LOCK_NB)) {
        fwrite($logfile, $message);
        flock($logfile, LOCK_UN);
        echo "Log message written successfully.\n";
    } else {
        echo "Could not obtain lock on logFile.log, message not recorded.\n";
    }
    
    fclose($logfile);
}

// Attempt to write to the log file
writeToLog("This is a normal log message.\n");
?>
