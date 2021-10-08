let cmp = 0;
for(let i = 1; i <= 5; i++) {
  for(let j = 1; j <= i; j++) {
    for(let k = 1; k <= j; k++) {
      cmp++;
    }
}
}
console.log(cmp);
