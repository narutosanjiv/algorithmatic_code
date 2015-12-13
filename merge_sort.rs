use std::io::prelude::*;
use std::io::BufReader;
use std::fs::File;

fn main() {
    let f = File::open("DuplicateIntegerArray.txt").unwrap();
    let reader = BufReader::new(f);
    let mut v: Vec<u32> = Vec::new();
    for line in reader.lines() {
        let line = line.unwrap();
        v.push(line.parse::<u32>().unwrap());
        //println!("{}", line.parse::<u32>().unwrap());
    }
    let length = v.len() - 1;
    merge_sort(& mut v, 0, length);

}

fn _merge_fn(arr: & mut Vec<u32>, l: usize, m: usize, r: usize){

    let mut i:usize;
    let mut j: usize;
    let mut k: usize;
    let n1: usize = m - l + 1;
    let n2: usize =  r - m;

    let mut R: Vec<u32> = Vec::new();
    let mut L: Vec<u32> = Vec::new();

    /* Copy data to temp arrays L[] and R[] */
    for i in 0..n1 {
        L.push(arr[l + i]);

    }
    for j in 0..n2 {
        R.push(arr[m + 1+ j]);
    }

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0;
    j = 0;
    k = l;
    while i < n1 && j < n2
    {
        if L[i] <= R[j]
        {
            arr[k] = L[i];
            i = i +1;
        }
        else
        {
            arr[k] = R[j];
            j = j + 1;
        }
        k = k + 1;
    }

    /* Copy the remaining elements of L[], if there are any */
    while i < n1
    {
        arr[k] = L[i];
        i = i + 1;
        k = k + 1;
    }

    /* Copy the remaining elements of R[], if there are any */
    while j < n2
    {
        arr[k] = R[j];
        j = j + 1;
        k = k + 1;
    }
}

fn merge_sort(vec: &mut Vec<u32>, l: usize, r: usize){
    if l < r {
        let m = (l + r)/2;
        merge_sort(vec, l, m);
        merge_sort(vec, m + 1, r);
        _merge_fn(vec, l, m, r);
    }
}
