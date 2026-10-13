<?php

require_once 'auth.php';

// Pass an array of all roles allowed to view this page
authorise(['admin', 'staff', 'student', 'guest', 'unauth']);

session_start();

// Instead of destroying the whole session, just clear the user data
// This is more reliable for "Flash Messages"
unset($_SESSION['user_id']);
unset($_SESSION['username']);
unset($_SESSION['access_level']);

// Set the flash message
$_SESSION['logout_message'] = "You have successfully logged out.";

header("Location: index.php");
exit();
