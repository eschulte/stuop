module A17 = Map.Make(String);;
let a1 = ref [] in
    let a2 = ref [] in
    let a3 = ref [] in
    let a4 = ref [] in
    try
      while true do
        a1 := List.append !a1 [read_line ()]
      done
    with _ -> begin
        let a5 = ref 0 in
        let a6 = ref 0 in
        let a7 = ref A17.empty in
        let a8 = ref A17.empty in
        while !a5 < List.length !a1 do
          let a9 = (List.nth !a1 !a5) in
          let a10 = (List.nth !a1 (!a5+1)) in
          if not(A17.mem a10 !a8) then begin
                                      a8 := A17.add a10 [a9] !a8 ;
                                      if (A17.mem a9 !a7) then
                                        a7 := A17.add a9 ((A17.find a9 !a7) + 1) !a7
                                      else begin a7 := A17.add a9 1 !a7 ;
                                                 a6 := !a6 + 1 end;
                                    end
          else begin
              if not(List.mem a9 (A17.find a10 !a8)) then begin
                                                         let a11 = List.append [a9] (A17.find a10 !a8) in
                                                         a8 := A17.add a10 a11 !a8 ;
                                                         if (A17.mem a9 !a7) then
                                                           a7 := A17.add a9 ((A17.find a9 !a7) + 1) !a7
                                                         else begin a7 := A17.add a9 1 !a7 ;
                                                                    a6 := !a6 + 1 end ;
                                                       end
            end ;
          if (not(A17.mem a10 !a7)) then begin
                                        a7 := A17.add a10 0 !a7 ;
                                        a6 := !a6 + 1 ;
                                      end ;
          a5 := !a5+2 ;
        done ;
        while !a6 > 0 do
          a3 := A17.fold (fun a12 a13 a14 -> if a13==0 then List.append a14 [a12] else a14) !a7 [];
          if List.length !a3 == 0 then a4 := List.append !a4 [1] ;
          let a15 = (List.nth !a3 0) in
          a2 := List.append !a2 [a15] ;
          a7 := A17.add a15 1000 !a7;
          a6 := !a6 - 1;
          if (A17.mem a15 !a8) then begin
                                   a3 := [] ;
                                   let a16 = A17.find a15 !a8 in
                                   a7 := List.fold_right (fun a12 a14 ->
                                                          let old = A17.find a12 a14 in
                                                          A17.add a12 (old-1) a14
                                                         ) a16 !a7
                                 end;
        done;
        if (List.length !a4 == 0) then List.iter print_endline !a2 else print_string "cycle" ;
      end
