module A35 = Set.Make(String);;
let a1 = ref [] in
    try
      while true do
        let a2 = read_line () in
        let a3 = read_line () in
        a1 := [a2;a3] :: !a1
      done
    with _ -> begin
        let a4 = !a1 in
        let a5 = List.flatten a4 in
        let a6 = A35.cardinal (List.fold_left (fun a24 a7 -> A35.add a7 a24)
                                              A35.empty
                                              a5) in
        let a28 a12 a8 = compare a12 a8 in
        let a29 a27 = List.sort (fun a12 a8 -> compare a12 a8)
                                (let a30 a9 = List.fold_left
                                                (fun a24 a20 ->
                                                 let a31 a10 a11 a12 = if a10 = a11 then a12 else a11 :: a12 in
                                                 match a24 with
                                                 | []     -> [a20]
                                                 | [hd]   -> a31 hd a20 a24
                                                 | hd::tl -> a31 hd a20 a24)
                                                []
                                                (List.sort a28 a9) in
                                 let a13 = a30 (List.map (fun a20 -> List.hd a20) a27) in
                                 let a14 = a30 (List.map (fun a20 -> List.nth a20 1) a27) in
                                 let a32 a15 a16 = List.fold_left (fun a24 a20 -> a24 || a20 = a15) false a16 in
                                 (List.filter
                                    (fun a20 -> not (a32 a20 a13))
                                    a14)
                                ) in
        let a17 = ref [] in
        let a33 a18 a27 =
          let a19 = List.filter (fun a25 -> not ((List.nth a25 1) = a18)) a27 in
          a17 := List.filter (fun a20 -> not (a18 = a20)) !a17;
          let a21 =
            let a22 = List.map
                        (fun a25 -> List.hd a25)
                        (List.filter (fun a25 -> (List.nth a25 1) = a18) a27)
            in
            List.filter
              (fun a23 ->
               List.fold_left
                 (fun a24 a25 -> a24 && not ((List.nth a25 1) =
                                               a23) && not ((List.hd a25) = a23))
                 true
                 a19)
              a22
          in
          a17 := !a17 @ a21;
          let a26 = List.sort a28 (!a17 @ (a29 a19)) in
          (a26, a19)
        in
        let rec a34 (a26, a27) = match a26 with
          | []     -> []
          | [a11]    -> a11 :: (a34 (a33 a11 a27))
          | hd::tl -> hd :: (a34 (a33 hd a27))
        in
        let out = a34 ((a29 a4), a4) in
        if (List.length out) == a6 then
          List.iter print_endline out
        else
          print_endline "cycle"
      end
