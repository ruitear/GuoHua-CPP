<?php
$dirname='E:\\OneDrive\\liurui-doc\\CCPR';
$dir_handle=opendir($dirname) or die("打开失败！");
$handle=fopen('C:\\Users\\liu-rui\\Desktop\\libb.txt', "w+");
while ($file=readdir($dir_handle)) {
	if($file!="."&&$file!="..")
		fwrite($handle, $file."\r\n");
}
echo "Complate!<br>";
fclose($handle);
?>
