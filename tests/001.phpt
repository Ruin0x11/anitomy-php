--TEST--
Check if anitomy is loaded
--SKIPIF--
<?php
if (!extension_loaded('anitomy')) {
    echo 'skip';
}
?>
--FILE--
<?php
echo 'The extension "anitomy" is available';
?>
--EXPECT--
The extension "anitomy" is available
