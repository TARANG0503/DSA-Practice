<?php
/*
Set time to hours ago by Tobi Adeoye @olusure on GitHub 
*/

function set_time($clock) {
global $set_user;
$realtime = time();
$blop = $clock + ($set_user['sdvig'] * 3600);
$blop = $clock + ($set_user['sdvig'] * 3600);
$flip=round(($realtime-$blop)/60);
if($flip==0){
$flip= 'a few second ago';
}
if($flip >0 && $flip < 60){
$flip= $flip . ' minutes ago';
}
if($flip>=60 && $flip<120){
$flip=round($flip/60);
$flip=$flip . ' hours ago';
}
if($flip>=120 && $flip<180){
$flip=round($flip/60);
$flip=$flip . ' hours ago';}
if($flip>=180 && $flip<240){
$flip=round($flip/60);
$flip=$flip . ' hours ago';
}
if($flip>=240 && $flip<300){
$flip=round($flip/60);
$flip=$flip . ' hours ago';
}
if($flip>=300 && $flip<360){
$flip=round($flip/60);
$flip=$flip . ' hours ago';
}
if($flip>=360 && $flip<420){
$flip=round($flip/60);
$flip=$flip . ' hours ago';
}
if($flip>=420 && $flip<480){
$flip=round($flip/60);
$flip=$flip . ' hours ago';
}
if($flip>=480 && $flip<540){
$flip=round($flip/60);
$flip=$flip . ' hours ago';
}
if($flip>=540 && $flip<600){
$flip=round($flip/60);
$flip=$flip . ' hours ago';
}
if($flip>=600 && $flip<660){
$flip=round($flip/60);
$flip=$flip . ' hours ago';
}
if($flip>=660 && $flip<720){
$flip=round($flip/60);
$flip=$flip . ' hours ago';
}
if($flip>=720 && $flip<780){
$flip=round($flip/60);
$flip=$flip . ' hours ago';
}
if($flip>=780 && $flip<820){
$flip=round($flip/60);
$flip=$flip . ' hours ago';
}
if($flip>=820 && $flip<880){
$flip=round($flip/60);
$flip=$flip . ' hours ago';
}
if($flip>=880 && $flip<920){
$flip=round($flip/60);
$flip=$flip . ' hours ago';
}
if($flip>=920 && $flip<980){
$flip=round($flip/60);
$flip=$flip . ' hours ago';
}
if($flip>=980 && $flip<1020){
$flip=round($flip/60);
$flip=$flip . ' hours ago';
}
if($flip>=1020 && $flip<1080){
$flip=round($flip/60);
$flip=$flip . ' hours ago';
}
if($flip>=1080 && $flip<1140){
$flip=round($flip/60);
$flip=$flip . ' hours ago';
}
if($flip>=1140 && $flip<1200){
$flip=round($flip/60);
$flip=$flip . ' hours ago';
}
if($flip>=1200 && $flip<1260){
$flip=round($flip/60);
$flip=$flip . ' hours ago';
}
if($flip>=1260 && $flip<1320){
$flip=round($flip/60);
$flip=$flip . ' hours ago';
}
if($flip>=1320 && $flip<1380){
$flip=round($flip/60);
$flip=$flip . ' hours ago';
}
if($flip>=1380 && $flip<1440){
$flip=round($flip/60);
$flip=$flip . ' hours ago';
}

if ($flip>=1440 && $flip<2880){
$flip=round($flip/60/24);
$flip='yesterday';
}

if ($flip>=2880){
$flip = date("F d h:ia", $blop);
}
return $flip;

}
?>
