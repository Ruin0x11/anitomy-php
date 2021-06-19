--TEST--
anitomy_parse() Option: allowed_delimiters
--SKIPIF--
<?php
if (!extension_loaded('anitomy')) {
    echo 'skip';
}
?>
--FILE--
<?php
$options = ["allowed_delimiters" => ""];
$ret = anitomy_parse("[Kamigami] Psycho-Pass - 06 [1280x720 x264 AAC Sub(CH,JP)].mkv", $options);

var_dump($ret);
?>
--EXPECT--
array(5) {
  ["file_extension"]=>
  string(3) "mkv"
  ["file_name"]=>
  string(58) "[Kamigami] Psycho-Pass - 06 [1280x720 x264 AAC Sub(CH,JP)]"
  ["anime_title"]=>
  string(16) "Psycho-Pass - 06"
  ["release_group"]=>
  string(8) "Kamigami"
  ["success"]=>
  bool(true)
}
