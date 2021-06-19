--TEST--
anitomy_parse() Option: parse_episode_title
--SKIPIF--
<?php
if (!extension_loaded('anitomy')) {
    echo 'skip';
}
?>
--FILE--
<?php
$options = ["parse_episode_title" => false];
$ret = anitomy_parse("[shirt] Pokemon Master Journeys S24E01 - To Train or Not to Train! (Teletoon)", $options);

var_dump($ret);
?>
--EXPECT--
array(6) {
  ["file_name"]=>
  string(77) "[shirt] Pokemon Master Journeys S24E01 - To Train or Not to Train! (Teletoon)"
  ["anime_season"]=>
  string(2) "24"
  ["episode_number"]=>
  string(2) "01"
  ["anime_title"]=>
  string(23) "Pokemon Master Journeys"
  ["release_group"]=>
  string(5) "shirt"
  ["success"]=>
  bool(true)
}
