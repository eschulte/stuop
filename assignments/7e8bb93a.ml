let a1 = ref [] in
    try
      while true do
        a1 := (read_line ()) :: !a1
      done
    with a14 -> begin
        let a2 = List.sort
                   (fun a3 a4 -> compare a4 a3)
                   (List.fold_right
                      (fun a5 a6 ->
                       if List.mem a5 a6 then a6 else a5::a6)
                      !a1 [] )
        in
        let a7, a8 = List.fold_right
                       (fun a9 (a10, a11) -> (a9::a11, a10) ) !a1 ([], []) in
        let a12 = List.sort
                    (fun (a14, a13) (a14, a15) -> compare a15 a13)
                    (List.combine a8 a7) in
        let rec a27 a24 a16 (a25, a17) = (
          if List.mem a24 a16 then (a25, true) else
            if a17 || List.mem a24 a25 then (a25, a17) else (
              let (a18,a26) =  List.fold_right (
                                   fun (a19, a20) a21 ->
                                   if a24 = a19 then (a27 a20 (a24::a16) a21) else a21
                                 ) a12 (a25, a17) in
              (a18@[a24], a26)
            )
        ) in
        let (a22, a23) = List.fold_right
                           (fun a24 (a25, a26) ->
                            if List.mem a24 a25 then (a25, a26) else a27 a24 [] (a25,a26) )
                           a2 ([], false) in
        if a23 then print_endline "cycle" else List.iter print_endline a22;
      end
