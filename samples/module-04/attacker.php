<?php
// Simulating an attacker holding a lock on the log file indefinitely
$logfile = fopen("logFile.log", "a");

// Acquire an exclusive lock and do not release it for a long time
if (flock($logfile, LOCK_EX)) {
    echo "Attacker has obtained the lock and is holding it...\n";
    sleep(300); // Hold the lock for 300 seconds (5 minutes)
    flock($logfile, LOCK_UN); // Unlock after 5 minutes
} else {
    echo "Could not obtain lock on logFile.log\n";
}

fclose($logfile);
?>
