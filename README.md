# jeet-five
A PHP extension just like npm five

## Environment
 - PHP-7.1.5

## Basic
```php
    five(); // 5
    five() + five(); // 10
    five() - five(); // 0
    five() * five(); // 25
    five() / five(); // 1
```

## Multilingual
```php
    five_english(); // five
    five_chinese(); // 五
    five_chinese_pinyin(); // wǔ
    five_chinese_financial(); // 伍
    five_japanese(); // 五
    five_korean(); // 오
    five_fern(); // ❤️
    // and more
```

## Cryptography
```php
    five_md5(); // e4da3b7fbbce2345d7772b0674a318d5
```

## Assertion
```php
    is_five(5); // true
    is_five(2); // false
```

## Reference
 - [five](https://github.com/jackdcrawford/five)

## License
 - MIT

