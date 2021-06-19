--TEST--
anitomy_parse() Empty strings
--SKIPIF--
<?php
if (!extension_loaded('anitomy')) {
    echo 'skip';
}
?>
--FILE--
<?php
$ret = anitomy_parse("");
var_dump($ret);

$ret = anitomy_parse("[");
var_dump($ret);
?>
--EXPECT--
array(1) {
  ["success"]=>
  bool(false)
}
array(1) {
  ["success"]=>
  bool(false)
}
