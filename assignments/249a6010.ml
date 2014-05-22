let a1 = ref [] in
    try
      while true do
        a1 := (read_line ()) :: !a1
      done
    with _ -> begin
        let a2 = List.sort
                   (fun a3 a4 ->
                    compare a4 a3)
                   !a1
        in
        let rec a17 a12 =
          match a12 with [] -> true | hd::tl -> (hd mod 2 = 1 && (a17 tl)) in
        let rec a18 a12 =
          match a12 with [] -> [] | one::[] -> one::[] | one::two::tl  -> if one = two then a18 (a18 (two::tl))  else (one::(a18 (two::tl))) in
        let a5 = a18 a2 in
        let rec a19 a6 a12 a7 a10  =
          match a12 with [] -> a7 | hd::tl -> if a6 = hd then a19 a6 tl (a10::a7) (a10 + 1) else a19 a6 tl a7 (a10 + 1) in
        let a8 = List.rev (!a1) in
        let rec a20 a13 a12  =
          match a13 with [] -> (print_endline ("cycle"); exit 0) | hd::tl -> if a17 (List.rev (a19 hd a12 [] 0)) then hd else a20 tl a12 in
        let rec a21 a9 a12 a10 a11 =
          match a12 with [] -> a11 |hd::[] -> hd::a11 | hd::next::tl -> if next = a9&& a10 mod 2 = 0 then (a21 a9 tl (a10 + 2) a11) else (a21 a9 (next::tl) (a10 + 1) (hd::a11)) in
        let rec a22 a12 a13 a14 =
          match a13 with [] -> a14 | hd::tl -> let a15 = a20 a13 a12 in a22  (List.filter (fun a16 -> a16 != a15) a13 ) (a15::a14) in
        List.iter print_endline (List.rev (a22 a8 (List.rev a5) []))
      end
