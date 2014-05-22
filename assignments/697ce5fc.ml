let a8 = ref [] in
    try
      while true do
        a8 := !a8 @ [(read_line ())]
      done
    with a2 -> begin
        let a16 a6 a7 = List.fold_left (fun a10 a1 -> if a1 = a6 then a10 else a1 :: a10 ) [] a7 in
        let a17 (a2 : 'a) : 'b list = [] in
        let a18 a9 a3 a4 = fun a5 ->
          if a5 = a3 then (a4 :: a9 a5) else a9 a5
        in
        let a19 a9 a4 = fun a5 ->
          a16 a4 (a9 a5)
        in
        let a20 a6 a7 = if List.mem a6 a7 then a7 else a6 :: a7 in
        let rec a21 a8 a9 a10 : ('a -> 'a list) * ('a list) = match a8 with
          | t :: dep :: tl -> a21 tl (a18 a9 t dep) (a20 dep (a20 t a10))
          | a2 -> (a9, a10)
        in
        let rec a22 a9 a15 a10 = match a15 with
          | [] -> a10
          | hd :: tl when a9 hd == [] -> a22 a9 tl (hd :: a10)
          | a2 :: tl -> a22 a9 tl a10
        in
        let rec a23 a9 a15 a10 = match a15 with
          | [] -> a10
          | a2 ->
             (match (a22 a9 a15 []) with
              | [] -> ["cycle"]
              | a6 -> begin
                      let a11 = List.hd (List.sort (fun a12 a13 -> compare a12 a13) a6) in
                      a23 (a19 a9 a11) (a16 a11 a15) (a10 @ [a11])
                    end)
        in
        let a14, a15 = (a21 !a8 a17 []) in
        List.iter print_endline (a23 a14 a15 [])
      end
