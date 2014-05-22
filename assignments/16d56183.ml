let a20 a1 a2 =
  try (List.assoc a1 a2)
  with Not_found -> []
    in
    let a3 = ref [] in
    try
      while true do
        a3 := (read_line ()) :: !a3;
      done
    with _ -> begin
        try
          a3 := List.rev !a3;
          let a4 =
            let a21 a5 a15 =
              if List.mem a15 a5 then a5 else a15::a5
            in
            let a6 = List.fold_left a21 [] !a3
            in
            List.sort (fun a14 a15 -> compare a14 a15) a6
          in
          let a7 =
            let rec a22 a9 a10 =
              let rec a23 a11 a12 a13 =
                match a12 with
                | [] -> List.sort (fun a14 a15 -> compare a15 a14) a11
                | a14::a15::lst when a15 = a13 -> a23 (a14::a11) lst a15
                | _::tl -> a23 a11 (List.tl tl) a13
              in
              let a16 =
                (a23 [] !a3 (List.hd a10)) in
              match a10 with
              | [] -> a9
              | hd::[] -> (hd, a16)::a9
              | hd::tl -> a22 ((hd, a16)::a9) tl
            in
            a22 [] a4;
          in
          let a8 =
            let rec a22 a9 a10 =
              let rec a23 a11 a12 a13 =
                match a12 with
                | [] -> List.sort (fun a14 a15 -> compare a15 a14) a11
                | a14::a15::lst when a14 = a13 -> a23 (a15::a11) lst a14
                | _::tl -> a23 a11 (List.tl tl) a13
              in
              let a16 =
                (a23 [] !a3 (List.hd a10)) in
              match a10 with
              | [] -> a9
              | hd::[] -> (hd, a16)::a9
              | hd::tl -> a22 ((hd, a16)::a9) tl
            in
            a22 [] a4;
          in
          try
            let a17 =
              let rec a24 a18 a19 =
                let rec follow_path marked a18 a13 =
                  if List.mem a13 marked then invalid_arg "cycle" else
                    if List.mem a13 a18 then a18 else
                      let marked_2 = a13::marked in
                      let edges = List.assoc a13 a7 in
                      let a18 = List.fold_left (follow_path marked_2) a18 edges in
                      a13::a18
                in
                match a19 with
                | [] -> a18
                | hd::tl -> a24 (follow_path [] a18 hd) tl
              in
              let start, unmarked = List.partition (fun a14 -> (a20 a14 a8) = []) a4 in
              if (List.length start = 0) then ["cycle"] else a24 [] (List.sort (fun a14 a15 -> compare a15 a14) start)
            in
            if (List.length a17 < List.length a4) then print_endline "cycle" else List.iter print_endline a17;
          with _ -> print_endline "cycle"
        with
        | Not_found -> begin
                       print_endline "cycle"
                     end
      end
